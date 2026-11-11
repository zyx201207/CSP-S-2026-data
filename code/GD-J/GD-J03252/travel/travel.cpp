#include <bits/stdc++.h>
using namespace std;
int ans = 0;
bool a = 1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char s1[3],c1[5],s2[3],c2[5];
	for (int i = 0;i < 2;i++){
		cin >> s1[i];
	}for (int i = 0;i < 3;i++){
		cin >> c1[i];
	}for (int i = 0;i < 2;i++){
		cin >> s2[i];
	}for (int i = 0;i < 3;i++){
		cin >> c2[i];
	}for (int i = 0;i < 2;i++){
		if (s1[i] != s2[i]){
			a = 0;
			break;
		}
	}
	cout << a;
	ans++;
	if (a == 0){
		for (int i = 1;i <= 4-ans;i++)
			cout << 0;
		return 0;
	}
	a = 1;
	for (int i = 0;i < 2;i++){
		if (c1[i] != c2[i]){
			a = 0;
			break;
		}
	}
	cout << a;
	ans++;
	if (a == 0){
		for (int i = 1;i <= 4-ans;i++)
			cout << 0;
		return 0;
	}
	a = 1;
	for (int i = 2;i < 3;i++){
		if (!(c1[i] == 'A' && c2[i] == 'C' || c1[i] == 'C' && c2[i] == 'A' || c1[i] == 'A' && c2[i] == 'B' || c1[i] == 'B' && c2[i] == 'A' || c1[i] == 'C' && c2[i] == 'B' || c1[i] == 'B' && c2[i] == 'C' || c1[i] == 'D' && c2[i] == 'F' || c1[i] == 'F' && c2[i] == 'D')){
			a = 0;
		}
	}
	cout << a;
	ans++;
	if (a == 0){
		for (int i = 1;i <= 4-ans;i++)
			cout << 0;
		return 0;
	}
	a = 1;
	for (int i = 2;i < 3;i++){
		if (!(c1[i] == 'A' && c2[i] == 'B' || c1[i] == 'B' && c2[i] == 'A' || c1[i] == 'C' && c2[i] == 'B' || c1[i] == 'B' && c2[i] == 'C' || c1[i] == 'D' && c2[i] == 'F' || c1[i] == 'F' && c2[i] == 'D')){
			a = 0;
		}
	}
	cout << a;
	return 0;
}
