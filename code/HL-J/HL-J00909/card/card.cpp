#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],desk[N],cnt;
map<int,int> ans;
void find(int now){
	bool flag=false;
	for(int i=0;i<=cnt;i++){
		if(desk[i]==now){
			flag=true;
			cnt=i-1;
		}
		if(flag==true) desk[i]=0;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		cnt=-1;
		for(int j=i;j<n;j++){
			find(a[j]);
			desk[++cnt]=a[j];
		}
		for(int j=0;j<=cnt;j++){
			ans[desk[j]]++;
			desk[j]=0;
		}
	}
	for(map<int,int>::iterator it=ans.begin();it!=ans.end();it++) cout<<it->second<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}