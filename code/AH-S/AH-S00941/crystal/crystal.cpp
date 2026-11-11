#include<bits/stdc++.h>
using namespace std;
bool v=0,c1=1,c2=1;
long long n=0,m=0,a[501000],minn=INT_MAX,s=0,t=0,cnt=1,k,r;
double w=0.00;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	r=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		k=a[1]-a[2];
		if(a[i]!=i) c1=0;
		else if(a[i]-a[i+1]==k) c2=0;
		w=w+a[i];
	}
	w=w/n;
	for(int i=1;i<=n;i++){
		if(abs(w-a[i])<minn){
			minn=abs(w-a[i]);
			s=i;
		}
	}
	for(int q=1;q<=m;q++){
		minn=INT_MAX;
		t=0;
		for(int i=1;i<=n;i++){
			if(a[i]<=minn){
				minn=a[i];
				t=i;
			}
		}
		if(m>=a[s]-a[t]){
			m=m-a[s]+a[t];
			a[t]=a[s];
			cnt++;
			v=1;
		}
		else if(m==a[s]-a[t]&&v==0&&c1==0&&c2==0){
			cout<<"2"<<endl;
			return 0;
		}
		else if(m<a[s]-a[t]&&v==0&&c1==0&&c2==0){
			cout<<"1"<<endl;
			return 0;
		}
	}
	if(c1==1) cout<<cnt+1;
	else if(c2==1){
		if(r<k) cout<<cnt;
		else cout<<cnt+1;
	}
	else cout<<cnt;
	return 0;
}
