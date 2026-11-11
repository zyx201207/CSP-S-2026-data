#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005; 

int n,m;
int L[MAXN];
int ans[MAXN];
int Last[MAXN];

struct REMOVE{
	int start;
	int end;
}; 
vector<REMOVE> V;

bool cmp(REMOVE a,REMOVE b){
	return a.start < b.start;
}

void game(int start){
	int Vid = 0;
	while(V[Vid].start < start){
		Vid++;
	}
	for(;start < n;start++){
		if(V[Vid].start == start){
			start = V[Vid].end;
			while(V[Vid].start <= start){
				Vid++;
			}
		}else{
			ans[L[start]]++;
		}
	}
	 
}

int main(){ 
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < m;i++){
		Last[i+1] = -1;
	}
	for(int i = 0;i < n;i++){
		cin >> L[i];
		if(Last[L[i]] != -1){
			REMOVE temp;
			temp.start = Last[L[i]];
			temp.end = i-1;
			V.push_back(temp);
		}
		Last[L[i]] = i;
	}
	REMOVE temp;
	temp.start = 2147483647; 
	V.push_back(temp);
	sort(V.begin(),V.end(),cmp);
	
	for(int i = 0;i < n;i++){
		game(i);
	}
	
	for(int i = 0;i < m;i++){
		cout << ans[i+1] << ' ';
	}
	return 0;
}
