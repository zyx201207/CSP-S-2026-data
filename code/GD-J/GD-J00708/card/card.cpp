#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
queue<int> q;
long long n,m,a[MAXN],b[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	for(int i=0;i<n;i++){
		long long ci=i;
		while(ci!=n){
			int h=0;
			for(int j=0;j<q.size();j++){
				int y=q.front();
				if(y==a[ci]){
					for(int l=h;l<q.size();l++){
						q.pop();
					}
				}else{
					q.pop();
					q.push(y);
					h++;
				}
			}
			q.push(a[ci]);
			ci++;
		}
		for(int j=0;j<q.size();j++){
			b[q.front()]++;
			q.pop();
		}
	}
	for(int i=0;i<m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
