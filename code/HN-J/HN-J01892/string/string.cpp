#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
int n;
int a[MAXN];
char c[MAXN];
string s;
bool checkS(string st){
	int i = st.size() / 2;
    int j = st.size() / 2;
    while (i >= 0 && st.size() % 2 == 1){
    	if (st[i] != st[j]){
    		return 0;
		}
		i--;
		j++;
	}
	i = st.size() / 2 - 1;
    j = st.size() / 2;
	while (i >= 0 && st.size() % 2 == 0){
    	if (st[i] != st[j]){
    		return 0;
		}
		i--;
		j++;
	}
	return 1;
}
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++){
    	cin >> a[i] >> c[i];
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < a[i]; j++){
			s += c[i];
		}
	}
	if (checkS(s)){
		cout << 0;
		return 0;
	}
	
	return 0;
}


