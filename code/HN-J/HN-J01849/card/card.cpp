#include<bits/stdc++.h>
using namespace std;
int n, m, tine[30010], cards[30010];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>cards[i];
	}
	for(int q=1;q<=m;q++){
		string a;
		for(int i=q;i<=m;i++){
			bool w=false;
			for(int j=0;j<a.size();j++){
				if(a[j]-'0'==cards[i]){
					for(int k=a.size()-1;k>=j;k--)  a[k]--;
					w=true;
					break;
				}
			}
			if(w==false) a[a.size()]=cards[i]+'0';
		}
		for(int i=0;i<a.size();i++)  tine[a[i]='0']++;
	}
	for(int i=1;i<=m;i++)  cout<<tine[i]<<" ";
	return 0;
}
