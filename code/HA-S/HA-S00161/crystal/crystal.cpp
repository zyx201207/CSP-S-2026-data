#include <bits/stdc++.h>
using namespace std;
struct  a_t{
	int x;
	int sz;
};
bool cmp(a_t a,a_t b){
	return a.sz>b.sz;
}
int main(){
	/*freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);*/
	
	int n,m;
	cin>>n>>m;
	vector<int> a(n,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int c=0;
	vector<a_t> b(n-1,0);}
	sort(a.begin(),a.end());
	for(int i=0;i<n-1;i++){
		b[i].sz=a[i]-a[i+1];
		b[i].x=i;
    }
    
	cout<<c;
	
	/*fclose(stdin);
	fclose(stdout);*/
	return 0;
}
// 1 2 4 8 9
//9 8 4 2 1
//1 4 2 1
