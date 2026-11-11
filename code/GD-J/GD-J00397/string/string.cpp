#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
int a[N];
string c[N],f[N];
string s;
void solved(){
	int n,ans=0,b=1,cnt = 0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for(char c:s){
		f[b]=c;
		b++;
	}
	int k=s.size();
	int mid=k+1/2;
	for(int l=1,r=k;r<=mid;r--,l++){
		if(r<l){
			break;
		}
		if(f[r]!=f[l]){
			cnt++;
		}
	}
	cout<<cnt;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	solved();
	return 0;
} 
