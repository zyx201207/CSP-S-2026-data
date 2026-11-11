#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
vector<long long> new_a;
int n,m;
void find_max_and() {
}
void find_max_and2() {
	int MAX=-1,MAX_j=-1;
	int MAX_i=-1;
	for(int i=0; i<new_a.size(); i++) {
		for(int j=0; j<a.size(); j++) {
			if((new_a[i]&a[j])>=MAX) {
				MAX_i=i;
				MAX=new_a[i]&a[j];
				MAX_j=j;
			}
		}
	}
	a[MAX_j]=0;
	a.push_back(MAX);
	new_a[MAX_i]=0;
	new_a.push_back(MAX);
	
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		long long w;
		cin>>w;
		a.push_back(w);
	}
		int MAX=-1;
	int MAX_i=-1,MAX_j=-1;
	for(int i=0; i<a.size(); i++) {
		for(int j=0; j<a.size(); j++) {
			if((a[i]&a[j])>=MAX && i!=j) {
				MAX=a[i]&a[j];
				MAX_i=i;
				MAX_j=j;
			}
		}
	}
	a[MAX_i]=0;
	a[MAX_j]=0;
	
	a.push_back(MAX);
	new_a.push_back(MAX);
	for(int i=1; i<=m-1; i++) find_max_and2();
	int MAXX=new_a[0];
	for(int i=0; i<new_a.size(); i++) {
		if(new_a[i]>=MAXX){
			MAXX=new_a[i];
		}
		cout<<new_a[i]<<' ';
	}
	cout<<MAXX<<endl;
	return 0;
}
