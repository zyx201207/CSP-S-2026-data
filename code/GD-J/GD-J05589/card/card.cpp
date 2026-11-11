#include<bits/stdc++.h>
using namespace std;
vector<int>dt;
vector<int>cnt;
int fd(int s){
    for(int i=0;i<dt.size();i++){
        if(s==dt[i]){
            return i;
        }
    }
    return -1;
}
int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>a;
	for(int k=0;k<n;k++){
		cin>>a[k];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(fd(a[i])==-1){
                dt.insert(dt.end(),a[i]);
			}
			else{
                for(int i=dt.size()-1;i>=fd(a[i]);i--){
                    dt.pop_back();
                }
			}
		}
		for(int i=0;i<dt.size();i++){
            cnt[dt[i]]++;
		}
		for(int i=0;i<dt.size();i++){
            dt.pop_back();
		}
	}

	for(int i=0;i<m;i++){
        cout<<cnt[i];
	}
    return 0;
}

