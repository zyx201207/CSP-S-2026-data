#include<bits/stdc++.h>
using namespace std;
long long ans=0,a[200005];
char c[200005];
int main(){
	//GZ-J00101 贵阳市南明区李端棻中学 曾俊豪
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int s=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s+=a[i];
	}
	long long l=a[1],r=a[n];
	int i=1 ,j=n;
	while(i!=j){
		char w1=c[i],w2=c[j];
		long long p=l,q=r;
		if(w1!=w2){
			if(p>=q){
				ans+=q;
				l-=p-q;
				r=a[j--];	
			}
			else{
				ans+=p;
				l=a[i++];
				r-=q-p;
			}
		}
		else{
			if(p>=q){
				l-=p-q;
				r=a[j--];
			}
			else{
				l=a[i++];
				r-=q-p;
			}
		}
	}
	cout<<ans;
	return 0;
}
