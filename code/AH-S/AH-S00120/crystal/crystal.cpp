#include <bits/stdc++.h>
using namespace std;
int n,k,t2;
long long m;
long long a[500005];
long long b[500005];
long long ans,ans2=1,cnt3,cnt,t,t3;
long long b3[500005];
long long b4[500005];
long long c[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cnt=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1){
			if(a[i]==a[i-1]){
				k++;
			}
		}
	}
	if(k==n-1){
		cout<<n;
		return 0;
	}
	sort(a+1,a+1+n);
	bool g=0;
	for(int i=1;i<=n;i++){
		if(i>1&&(a[i]-a[i-1]==a[2]-a[1])){
			t2++;
		}
		if(i>1 && (a[i]-a[i-1]<=1)&&g==0){
			g=1;
		}
		b[i]=b[i-1]+a[i];
		b3[i]=a[i+1]-a[i];
		b4[i]=b4[i-1]+b3[i];
		//cout<<"b: "<<b4[i]<<" ";
	}
	//cout<<endl;
	if(m==1){
		if(g==0){
			cout<<1;
			return 0;
		}
	}
	if((t2==n-1)&&m==2){
		t3=a[2]-a[1];
		if(t3>2){
			cout<<1;
			return 0;
		}else{
			cout<<2;
			return 0;
		}
	}
	for(int i=2;i<=n;i++){
		cnt+=b4[i-1];
		cnt3=a[i]-a[1];
		t=i;
		ans=min(cnt/cnt3,t);
		ans2=max(ans,ans2);
		//cout<<"ans::"<<ans<<" ";
	}
	//cout<<"t:"<<t<<endl;
	if(ans2<1){
		cout<<1;
		return 0;
	}
	cout<<min(ans2,t);
	
	return 0;
}
