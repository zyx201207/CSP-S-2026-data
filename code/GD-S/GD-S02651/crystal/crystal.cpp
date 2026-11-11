#include<bits/stdc++.h>
using namespace std;

#define filename "crystal"
#define ___usefile___

#ifdef ___usefile___
	ifstream ____cin____(filename".in");
	ofstream ____cout____(filename".out");
	#define cin ____cin____
	#define cout ____cout____
#endif

int n,m,maxx = -1;
long long tmp,t;
bool flag = 1;

vector<long long>num;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	num.resize(n,0);
	for(int i = 0; i < n;i++){
		cin>>num[i];
	}
	sort(num.begin(),num.end());
	for(int i = 0; i < n;i++){
		if(i > 1){
			if((num[i]-num[i-1]) != (num[i-1]-num[i-2])){
				flag = 0;
			}else{
				t = tmp = num[i]-num[i-1];
			}
		}
	}
	if(flag){
		maxx = 0;
		long long sum = 0;
		while(sum <= m){
			sum+=t;
			t+=tmp;
			maxx++;
		}
	}else{
		for(int i = 0;i < n;i++){
			long long sum = 0,add = 0;
			vector<long long>tmp(i+1,0);
			for(int j = i-1;j >= 0;j--){
				tmp[j] = num[j+1]-num[j]+sum;
				add+=tmp[j];
				sum = tmp[j];
			}
			if(add > m){
				sort(tmp.begin(),tmp.end());
				for(int j = tmp.size()-1;j >= 0;j--){
					add-=tmp[j];
					if(add <= m){
						maxx = max(maxx,j);
						break;
					}
				}
			}else{
				maxx = max(maxx,i+1);
			}
		}
	}
	cout<<maxx;
	return 0;
}
