#include <bits/stdc++.h>
using namespace std;


int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	int n,m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0;i < n;i++){
		cin >> a[i];
	}
	
	vector<int> live(m);
	for (int i = 0;i < m;i++)live.push_back(0);
	
	for (int i = 0;i < n;i++){
		int j = i;
		vector<int> safe;
		safe.push_back(a[j]);
		while (j != n - 1){
			int index = n - 1;
			while (a[index] != a[j])index--;
//			cout << i << ' ' << index << endl;
			if (index != n - 1){
				safe.push_back(a[index + 1]);
			}else break;
			j = index + 1;
		}
//		for (j = 0;j < safe.size();j++)cout << safe[j] << ' ';
//		cout << endl;
		for (j = 0;j < safe.size();j++){
			live[safe[j] - 1]++;
		}
	}
	for (int i = 0;i < m;i++)cout << live[i] << " ";
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
