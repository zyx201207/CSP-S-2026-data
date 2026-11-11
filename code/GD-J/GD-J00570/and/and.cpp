#include <bits/stdc++.h>
using namespace std;
long long a[200005],c[200005];
string b[200005];
long long sqrtll(int a,int b){
	int tmp=1;
	for(int i=0;i<b;i++){
		tmp*=a;
	}
	return tmp;
}
string bin(long long a){
	long long tmp=a;
	string s="000000000000000000000000000000";
	for(int i=0;i<30;i++){
		if(tmp/sqrtll(2,29-i)){
			b[i]='1';
			tmp%=sqrtll(2,29-i);
		}
	}
	return s;
}
int main(){
	freopen("and1.in","r",stdin);
	freopen("and.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=bin(a[i]);
	}
	for(int i=0;i<30;i++){
		int cnt=0;
		for(int j=0;j<n;j++){
			if(b[j][i]){
				cnt++;
			}
		}
		if(cnt>=m){
			for(int j=0;j<n;j++){
				if(!b[j][i]){
					a[j]=0;
					b[j]="000000000000000000000000000000";
				}
			}
		}
	}
	for(int i=0;i<m;i++){
		long long maxn=a[0];
		for(int j=1;j<n;j++){
			if(maxn<a[j]){
				maxn=a[j];
			}
		}
		c[i]=maxn;
		for(int j=0;j<n;j++){
			if(maxn==a[j]){
				a[j]=0;
				break;
			}
		}
	}
	int ans=c[0];
	for(int i=1;i<m;i++){
		ans&=c[i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
