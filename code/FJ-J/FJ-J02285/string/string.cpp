#include<bits/stdc++.h> 
using namespace std;
int n;
int a[200005][2];
long long L;
long long l,r;
int r1,r2;
int l1,l2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char c;
		cin>>a[i][0]>>c;
		a[i][1]=(int)c;
		L+=a[i][0];
	}
	if(L%2==0){
		l=L/2;
		r=L/2+1;
	}else{
		l=L/2;
		r=L/2+2;
	}
	L=0;
	for(int i=1;i<=n;i++){
		L+=a[i][0];
		if(L>=l&&l1==0){
			l1=i;
			l2=a[i][0]-L+l;
		}
		if(L>=r){
			r1=i;
			r2=a[i][0]-L+r;
			break;
		}
	}
		/*cout<<"l:"<<l1<<" "<<l2<<endl;
		cout<<"r:"<<r1<<" "<<r2<<endl<<endl;*/
	long long ans=0;
	while(l1!=0&&r1!=n+1){
		//l2
		//a[r1][0]-r2+1
		if(l2>a[r1][0]-r2+1){
			if(a[l1][1]!=a[r1][1])ans+=a[r1][0]-r2+1;
			l2-=a[r1][0]-r2+1;
			r1++;r2=1;
		}else{
			if(a[l1][1]!=a[r1][1])ans+=l2;
			r2+=l2;
			l1--;l2=a[l1][0];
		}
		/*cout<<"l:"<<l1<<" "<<l2<<endl;
		cout<<"r:"<<r1<<" "<<r2<<endl;
		cout<<"ans="<<ans<<endl<<endl;*/
	}
	cout<<ans;
	return 0;
}
