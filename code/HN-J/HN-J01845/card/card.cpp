#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

int a[N];
int t[N];

bool l[N];

int ans[N];

inline int read(){
	int x=0;char s=getchar(),ss=' ';
	while(!isdigit(s)) ss=s,s=getchar();
	while(isdigit(s)) x=(x<<3)+(x<<1)+s-'0',s=getchar();
	return (ss=='-'?-x:x);
}

signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;
	
	if(n <= 500 && m <= 200){	
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		for(int c=1;c<=n;c++){
			for(int i=c;i<=n;i++){
				l[i]= 0;
				t[a[i]] = 0;
			}
			
			for(int i=c;i<=n;i++){
				if(t[a[i]]){
					for(int j=t[a[i]];j<i;j++){
						l[j] = 1;
					}
				}
				
				t[a[i]] = i;
			}
			
			for(int i=c;i<=n;i++){
				if(!l[i]){
					ans[a[i]]++;
				}
			}
		} 
	
		for(int i=1;i<=m;i++){
			cout << ans[i] << ' ';
		}
		cout << '\n';
	}
	else{
		for(int i=1;i<=n;i++){
			int x;
			cin >> x;
			t[x] = i;
		}
		
		for(int i=1;i<=m;i++){
			cout << t[i] << ' ';
		}
	
		cout << '\n';
	}

	return 0;
}

