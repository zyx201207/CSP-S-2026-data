#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//
	int n,m;
	cin>>n>>m;
	
	
	vector<int> v;
	int shu=0;
	for(int l=0;l<n;++l){
		cin>>shu;
		v.push_back(shu);
	}
	
	
	int max=0;
	for(int i=0;i<n-m+1;++i){
		for(int j=i+1;j<n;++j){
			if((v[i] & v[j])>max){
				max=v[i] & v[j];
			}
		}
	}
	
	
	cout<<max<<endl;
	return 0;
}
