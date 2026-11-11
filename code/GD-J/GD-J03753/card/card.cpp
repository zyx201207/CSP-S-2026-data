#include <bits/stdc++.h>
using namespace std;
constexpr int N = 3e5+5;
vector<int> fd(N,1e9); //元素，第一次出现的下标 
int a[N]; 
vector<int> tns(N);
long long cnt[N];
bool flag = true;
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++) {
		cin>>a[i];
		if(a[i+1]<=a[i]) flag = false;
	}
	if(flag) {
		for(int i = n;i>=1;i--){
			cout<<a[i]<<' ';
		}
	}
	for(int turns = 1;turns <= n;turns++){
		//cout<<"new turn "<<turns<<endl;
		tns.clear();
		fd.clear();
		fd.resize(N,1e9);
		int i = 1,ri = turns; //ri = a中的下标,i = 牌堆尾 
		while(ri<=n){
			//cout<<"new while,id="<<turns<<" real id = "<<ri<<endl;
			//cout<<"fd ri="<<fd[a[ri]]<<" a ri="<<a[ri]<<endl;
			if(fd[a[ri]]!=1e9&&fd[a[ri]]<i){
				i = fd[a[ri]];
				//cout<<"find record! "<<ri<<" i = "<<i<<endl;
			}else fd[a[ri]] = i;
			tns[i] = a[ri];
			i++,ri++;
		}
		//cout<<"while finished,i="<<i<<endl;
		for(int t = 1;t<i;t++){
			cnt[tns[t]]++;
			//cout<<"cnt "<<t<<"tns t "<<tns[t]<<" is "<<cnt[tns[t]]<<endl;
		}
		//cout<<"-------------------------------------------"<<endl;
	}
	for(int i = 1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
