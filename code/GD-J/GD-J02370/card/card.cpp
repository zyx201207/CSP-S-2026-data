#include<bits/stdc++.h> 
using namespace std;

long long n,m,a=1;
vector<int> v(n+5,0);
vector<int> s(n+5,0);
vector<int> ans(n+5,0);

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	while(n-a>=0){
		for(int q=1;q<=4;q++){
			cin >> s[q];
		}
		for(int i=a;i<=n;i++){
			v[s[i]]++;
			if(v[i]>=2){
				for(int j=i;i>=1;j--){
					v[j]=0;
				}
				v[s[i]]++;	
		    }
		}
		for(int j=1;j<=n;j++){
			if(v[j]>0){
				ans[j]++;
			}
		}
		a++;
	}
	for(int i=1;i<=m;i++){
		cout << ans[i]<< " ";
	}
	return 0;
}
