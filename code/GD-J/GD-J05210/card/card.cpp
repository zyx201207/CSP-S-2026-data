#include<bits/stdc++.h>
using namespace std;
int n,m,ans[500005],a[500005];
string s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=n;i++){
		string s="";
		for (int j=i;j<=n;j++){
			if (s.find(a[j]+'0')>5e5){
				s+=a[j]+'0';
			}
			else {
				int t=s.find(a[j]+'0');
				s.erase(t,s.size()-t);
				s+=a[j]+'0';
			}
		}
		for (int j=0;j<s.size();j++){
			ans[s[j]-'0']++;
		}
	}
	for (int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
