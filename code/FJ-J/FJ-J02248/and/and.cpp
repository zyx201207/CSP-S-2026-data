#include<bits/stdc++.h>
using namespace std;
bool cmp(string a,string b){
	for(int i=1;i<=21;i++){
		if(a[i]>b[i]){
			return a>b;
		}
	}
	return a>b;
}
long long a[200001],t[22];
string s[200001]="00000000000000000000000";
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
//		string s="00000000000000000000000";
		int f=21;
		while(a[i]>0){
			s[i][f]=char(a[i]%2+48);
			a[i]/=2;
			f--;
		}
	}
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=21;i++){
		t[i]=1;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=21;j++){
			if(s[i][j]=='0'){
				t[i]=0;
			}
		}
	}
	int sum=0;
	int flag=0;
	for(int i=1;i<=21;i++){
		if(t[i]==1){
			flag=1;
		}
		if(flag){
			sum*=2;
			sum+=t[i];
		}
	}
	cout<<sum<<endl;
	return 0;
}

