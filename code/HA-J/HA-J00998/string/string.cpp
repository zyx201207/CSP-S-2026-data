#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,cnt = 0;
ll TheLess;
ll TheLen[300005] = {};
char TheWord[300005] = {};

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;++i){
		cin >> TheLen[i] >> TheWord[i];
	}
	
	int lIndex = 1;
	int rIndex = n;
	while(lIndex <= rIndex){
		TheLess = min(TheLen[lIndex],TheLen[rIndex]);
		if(TheWord[lIndex] != TheWord[rIndex]){
			cnt += TheLess;
		}
		TheLen[lIndex] -= TheLess;
		TheLen[rIndex] -= TheLess;
		if(TheLen[lIndex] <= 0)++lIndex;
		if(TheLen[rIndex] <= 0)--rIndex;
	}	
	
	cout << cnt;
	
	return 0;
}
