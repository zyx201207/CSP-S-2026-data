#include<bits/stdc++.h>
using namespace std;
int n,ansbaol,anscorre=-1e6+1,anson,anstw;
long long a[500005],m,c[500][500],zonghe;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int flag=1;
	for(int i=1;i<=n;i++){
		if(a[i+1]-a[i]!=a[2]-a[1]){
			flag=0;
			break;	
		}
	}
	if(n<=16){
		for(int i=n;i>=1;i--){
			for(int j=1;j<=n;j++){
				c[i][j]=a[i]-a[j];
			}
		}
		for(int i=n;i>=2;i--){
			ansbaol=0;
			zonghe=0;
			for(int j=i-1;j>=1;j--){
				//cout<<c[i][j]<<" ";
				if(zonghe+c[i][j]>m)continue;
				else {
					zonghe+=c[i][j];
					ansbaol++;
				}	
			}
			ansbaol+=1;
			//cout<<ansbaol<<" ";
			anscorre=max(anscorre,ansbaol);
			//cout<<endl;
		}
		//cout<<endl;
		cout<<anscorre;
		return 0;
	}//暴力求法（n<=16) 
	else if(flag==1){
		long long sum=0;
		for(int i=n-1;i>=1;i--){
			long long x=a[n]-a[i];
			if(sum+x>m){
				cout<<n-i;
				break;
			}
			else sum+=x;
		}
		return 0;
	}//等差数列求法 
	else{
		long long sum=0;
		for(int i=1;i<=n-1;i++){
			sum+=a[n]-a[i];
		}
		int i=1,j=n;
		long long p=sum;
		while(sum>m){
			sum-=(j-i)*(a[j]-a[j-1]);
			j-=1;
			//cout<<sum<<endl;
		} 
		//cout<<endl;
		//cout<<j-i+1<<endl<<endl<<endl;
		anson=j-i+1;
		sum=p;
		i=1,j=n;	
		while(sum>m){
			sum-=a[j]-a[i];
			i+=1;
			//cout<<sum<<endl;
		} 
		//cout<<endl;
		//cout<<j-i+1;
		anstw=j-i+1;
		cout<<max(anson,anstw);
		return 0;
	}//看yunqi了 
	return 0;
}
