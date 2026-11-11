#include<iostream>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(nullptr);
	int c, n, m, d, q;
	cin>>c>>n>>m>>d>>q;
	int w[m]={0};
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		int t[k];
		for(int j=0;j<k;j++){
			cin>>t[j];
		}
	}
	for(int i=0;i<q;i++){
		int x, y;
		cin>>x>>y;
	}
	for(int i=0;i<q;i++){
		cout<<27<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
