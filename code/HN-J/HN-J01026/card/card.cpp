#include<bits/stdc++.h>
using namespace std;

#define LEN (int)(2*(1e5))+5
int n,m,ns[LEN],tag[(int)1e6],cao[LEN],ccnts[LEN];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i=0;i<n;i++) {
		cin >> ns[i];
		tag[i] = -1;
	}
	
	int tail = 0;
	int ccnt = 0;
	for (int j=0;j<n;j++){
		for (int i=0;i<n;i++) tag[i] = -1;
		tail=0;
		for (int i=j;i<n;i++) {
			if (tag[ns[i]] == -1) {
				tag[ns[i]] =  tail;
				cao[tail] = ns[i];
				tail++;
			} else {
				tail = tag[ns[i]];
				tag[ns[i]] =  tail;
				cao[tail] = ns[i];
				tail++;
			}
		}
		
		for (int i=0;i<tail;i++) {
			ccnts[cao[i]]++;
		}
	}
	
	for (int i=0;i<LEN;i++) {
		if (ccnts[i] != 0)	cout << ccnts[i] << " ";
}
	
	return 0;
} 
