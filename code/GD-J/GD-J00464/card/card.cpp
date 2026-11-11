#include <bits/stdc++.h>
using namespace std;
long long jisu[350005];
long long sett[350005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	vector<long long> card(n+1);
	for(int i=0;i<n;i++){
		cin >> card[i];
	}
	stack<long long> s;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(sett[card[j]]==0){
				sett[card[j]]++;
				s.push(card[j]);
			}else{
				while(s.top()!=card[j]){
					sett[s.top()]--;
					s.pop();
				}
			}
		}
		while(!s.empty()){
			jisu[s.top()]++;
			sett[s.top()]--;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout << jisu[i]<< " ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
