#include<bits/stdc++.h>
using namespace std;
struct x{
	char a;
	long long b;
};
x b[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,sum=0;
	cin>>a;

	for(int i=1;i<=a;i++){
		cin>>b[i].b>>b[i].a;
		sum+=b[i].b;
	}
	sum/=2;
	int qq=0;
	long long j=0;
	/*for(int i=1;i<=a;i++){
		if(j+b[i].b==sum)break;
		if(j+b[i].b>sum){
			qq=1;
			x u=b[i+1];
			b[i]={b[i].a,sum-b[i].b};
			b[i+1]={b[i].a,b[i].b-(sum-b[i].b)};
			
			
			for(int j=i+2;j<=a+1;j++){
				x z=b[j];
				b[j]=u;
				u=z;
			}
			break;
		}
		j+=b[i].b;
	}*/
	long long k=0,kk=0,ans=0;
	int l=1,r=a;
	//if(qq==1)a++;

	while(l<=r and k<sum and kk<=sum){
		while(b[l].b>=b[r].b and l<=r and kk+b[r].b<=sum){
			k+=b[l].b-b[r].b;
			b[l].b-=b[r].b;

			kk+=b[r].b;
			if(b[l].a!=b[r].a){
				ans+=b[r].b;
			}
			r--;
			//cout<<l<<" "<<r<<" "<<ans<<endl;
		}

		if(b[l].b==0){
			l++;
		}
		if(l>r or k>sum or kk>sum or k+b[l].b>sum)break;
		while(b[l].b<=b[r].b and l<=r and k+b[l].b<=sum){
			kk+=(b[r].b-b[l].b);
			b[r].b-=b[l].b;

			k+=b[l].b;
			if(b[l].a!=b[r].a){
				ans+=b[l].b;
			}
			l++;
			//cout<<l<<" "<<r<<" "<<ans<<endl;
		}
		if(l>r or k>sum or kk>sum or kk+b[r].b>sum)break;
		if(b[r].b==0){
			r--;
		}
		//l++;
		//r++;
	}
	
	cout<<ans;
	return 0; 
}
