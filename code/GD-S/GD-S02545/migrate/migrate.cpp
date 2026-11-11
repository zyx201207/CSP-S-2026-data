#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll a[500005],ans,c,t,n,d,s,k,fl;
bool b[500005];

void ch(int x,int y){
	s=0;
	fl=0;
	memset(b,0,n+2);
	for(int i=x;i<y;i++){
		s+=a[i+1]-a[i];
		if(d<=s){
			s=0;
			k++;
			b[i]=1;
		}
	}
	for(int i=y;i>x;i--){
		s+=a[i]-a[i-1];
		if(d<s){
			s=0;
			k--;
			if(b[i]==0){
				fl=1;
			}
		}
	}
	if(k==0 && fl==1){
		ans++;
		
	}
	return;
}

void f(){
	cin>>n>>d;
	ans=0;
	for(int j=1;j<=n;j++){
		cin>>a[j];
	}
	for(int i=1;i<=n-3;i++){
		for(int j=i+3;j<=n;j++){
			ch(i,j);
		}
	}
	ans+=n%2;
	cout<<ans << "\n";
	return;
}

int main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		f();
	}
	
	fclose(stdin);fclose(stdout);
	return 0;
	
} 
