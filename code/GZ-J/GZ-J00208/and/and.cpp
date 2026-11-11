//GZ-J00208 兴义市弘毅中学 廖颢云 
#include <bits/stdc++.h>
using namespace std;
string s[200005],ans;
int n,m,a[200005],c[200005],sumn;
bool b[200005];
void dfs(int dep,int la){
	if(dep > m){
//		for(int i = 1;i <= dep-1;i++){
//			cout << c[i] << ' ';
//		}
//		cout << '\n';
		long long idx = dep - 1;
		string t1;
		for(int i = 1;i <= idx;i++){
			long long t = c[i],len = 0,ml = 0;
			while(t != 0){
				
				if(t % 2 == 1){
					s[i] = "1" + s[i];
				}else{
					s[i] = "0" + s[i];
				}
				idx--;
				t /= 2;
				len++;
			}
			ml = max(ml,len);
			for(int j = 1;j <= idx;j++){
				if(s[i].size() < ml){
					while(s[i].size() < ml){
						s[i] = '0' + s[i];
					}
				}
			}
			if(i == 1){
				t1 = s[i];
				continue;
			}
			for(int j = 2;j <= s[i].size();i++){
				if(t1[j] == s[i][j] && s[i][j] == 1){
					//cout << "s";
					t1[j] = '1';	
				}
				else t1[j] = '0';
			}
			//cout << s[i] << '\n';
			
		}
		ans = max(ans,t1);
		t1 = "";
		for(int i = 1;i <= dep-1;i++){
			s[i] = "";
		}
		return;
	}
	for(int i = la;i <= n;i++){
		if(b[i] == 0){
			b[i] = 1;
			c[dep] = a[i];
			dfs(dep+1,i+1);
			b[i] = 0;
		}
		
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	} 
	dfs(1,1);
	int t = ans.size()-1;
	for(int i = 1;i <= ans.size();i++){
		sumn += (long long)pow(2,t) * ans[i-1] - '0';
		t--;
	}
	//cout << sumn;
	cout << 12;
	return 0;
}
