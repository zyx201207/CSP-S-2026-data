#include <bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,m;
int a[N];
int res[N];
vector<int > t;
int findt(int target){
	if(t.empty()) return -1;
	for(int i=0;i<t.size();i++){
		if(t[i]==target) return i;
	}
	return -1;
}

void doit(){
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(findt(a[j])!=-1){
				int f=findt(a[j]),now=t.size();
				while(!t.empty()&&now>f){
					t.erase(t.end());	
					f--;
				} 
			}
			t.push_back(a[j]);
		}
		for(int i=0;i<t.size();i++){
			res[t[i]]++;
		}
		while(!t.empty()) t.erase(t.end());
	}
	
}
int main(){
	freopen("card.out","w",stdout);
	freopen("card.in","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	doit();
	for(int i=1;i<=m;i++) cout<<res[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
