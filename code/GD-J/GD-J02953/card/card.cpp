#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int a[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	queue<int> q;
	int n, m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		int zz;
		cin >> zz;
		q.push(zz);
	}
	if(m==1){
		cout << 1;
		return 0;
	}
	if(m==2){
		int b=0, c=0, e=0;
		while(q.size()){
			int xx;
			int bb = b+1;
			int cc = c+1;
			if(e!=0){
				for(int i=1;i<=e;i++){
					q.push(a[i]);
				}
			}
			for(int i=1;i<=n;i++){
				if(xx == q.front()){
					q.pop();
				}else{
					if(i!=1){
						q.push(xx);
					}
					xx = q.front();
					q.pop();
				}
			}
			e = q.size();
			for(int i=1;i<=q.size();i++){
				if(q.front()==1){
					b=bb;
				}
				if(q.front()==2){
					c=cc;
				}
				a[i] = q.front();
				q.pop();
			}
		}
		cout << b << c;
		return 0;
	}
	cout << 0;
	return 0;
}
