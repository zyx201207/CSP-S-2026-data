//GZ-J00297 Ёбндлн 
#include <bits/stdc++.h>
using namespace std;

string a[200004];
string max1="";
int ans=0;

void b(int x,int i){
	while(x!=0){
		char c=(x%2)+48;
		a[i]+=c;
		x/=2;
	}
}
bool c(string s,int sum1){
	if(s[sum1]>=max1[sum1]) return true;
}

bool cmp1(string a,string b){
	if(a.size()!=b.size()) return a.size()>b.size();
	int len=a.size()-1;
	for(int i=len;i>=0;i--){
		if(a[i]==b[i])continue;
		return a[i]>b[i];
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,x;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		b(x,i);
	}sort(a+1,a+1+n,cmp1);
	for(int i=1;i<=n;i++){
		cout<<a[i]<<' ';
	}max1=a[m];
	for(int i=m;i<n;i++){
		a[i]=a[i+1];
	}m--;n--;
	int len=max1.size()-1;
	for(int i=len;i>=0;i--){
		for(int j=1;j<=n;j++){
			if(c(a[j],i)){
				ans+=(max1[len]-48)*pow(2,len);
			}
		}
	}cout<<ans;
	fclose(stdin);
	fclose(stdout);
}

