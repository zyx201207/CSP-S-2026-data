#include<bits/stdc++.h>
using namespace std;
int n,m,o[1000005],h[10000005],t[1000005],tl = 0,hl,ans[1000005],x;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;++i){
		cin >> o[i];
		h[i] = o[i];
	}
//	for(int i = 1;i <= n;++i)cout << h[i];//
	hl = n;
	int g = 1;
	while(g <= n){
//		cout << "hl" << hl << " " << "starth";//
//		for(int i = 1;i <= hl;++i)cout << h[i] << ' ';//
//		cout << '\n';//
		int cnt = 4;
		while(cnt){
//			cout << "cnt" << cnt << endl;//
		--cnt;
		for(int i = 1;i < hl;++i){
			h[i] = h[i + 1];
		}
		h[hl] = 0;
		--hl;
		x = h[1];
//		cout << "x" << x << '\n';//
		for(int i = 1;i <= hl;++i){
			h[i] = h[i + 1];
		}
		h[hl] = 0;
		--hl;
		
		for(int i = 1;i <= tl;++i){
			if(t[i] == x){
				for(int j = i;j <= tl;++j){
					++hl;
					h[hl] = t[j];
					t[j] = 0;
				}
				tl -= (tl - i + 1);
			}
		}
		++tl;
		t[tl] = x;
//		cout << "tl" << tl << " " << "midt";//
//		for(int i = 1;i <= tl;++i)cout << t[i] << ' ';//
//		cout << '\n';//
	    }
		for(int i = 1;i <= n;++i){
			ans[o[i]] = 0;
			for(int j = 1;j <= tl;++j){
				if(t[j] == o[i]){
					++ans[o[i]];
				}
			}
		}
//		for(int i = 1;i <= tl;++i)cout << "endt" << t[i] << ' ';//
//		cout << '\n';//
		for(int i = 1;i <= tl;++i){
			++hl;
			h[hl] = t[i];
			t[i] = 0;
		}
		tl = 0;
		++g;
	}
	for(int i = 1;i <= n;++i)cout << ans[o[i]] << ' ';
	cout <<'\n';
	return 0;
}
