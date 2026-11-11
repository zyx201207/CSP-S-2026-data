#include<bits/stdc++.h>
using namespace std;
const int N=2*10e5+5;
long long b[N],u,m,n;
long long a[N];
bool p=0;
long long s=0,t=1;
int g(long long x){
	int y=0;
	while(x!=0){
		x/=2;
		y++;
		t*=2;
	}
	t/=2;
	return y;
}
void k(){
	int o=0;
	for(int i=n-1;i>=0&&a[i]>=t;i--){
		if((a[i]/t)%2==1){
			o++;
		}
	}
	if(m<=o){
		s+=t;
		int y=0;
		for(int i=n-1;i>=0&&a[i]>=t;i--){
		if((a[i]/t)%2==1){
			b[y]=a[i]-t;
			y++;
		}			
		}
		n=y;
		for(int i=0;i<n;i++){
			a[i]=b[i];
		}
	}
	if(t==1){
		return;
	}else{
		t/=2;
		k();
	}
}
int main(){
	freopen("and","r",stdin);
	freopen("and","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(a[n-1]==0){
		cout<<0;
		return 0;
	}else	if(a[n-1]==1){
		cout<<1;
		return 0;
	}
	u=g(a[n-1]);
	k();
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
