 #include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int arr[m] = {0};
    vector<int>vcommon;
    vector<int>v;
    vector<int>vplay;
    for(int i = 0;i<n;i++){
		int asdf;
		cin>>asdf;
		vcommon.push_back(asdf);
	}
	for(int i = 0;i<n;i++){
		v = vcommon;
		vplay.clear();
		int vlen = v.size();
		for(int j = 0;j<vlen;j++){
			int vplaylen = vplay.size();
			for(int k = 0;k<vplaylen;k++){
				if(vplay[k] == v[j]){
					vplay.erase(vplay.begin()+k,vplay.end());
				}
			}
			vplay.push_back(v[j]);
		}
		int vplaylen = vplay.size();
		for(int j = 0;j<vplaylen;j++){
			arr[vplay[j]-1]++;
		}
		vcommon.erase(vcommon.begin());
	}
	for(int i : arr){
		cout<<i<<' ';
	}
    return 0;
 }
