#include <bits/stdc++.h>
using namespace std;

long long n,m,c,j,cut,zong;
long long a[1000000000000],cha[1000000000000];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//输入 
    cin>>n>>m;
	for(int i =0;i<n;i++){
		cin>>a[i];
	}
	//排序 
	sort(a,a+n);
	//两值之差 
	for(int i = 0;i < n - 1;i++){
		cha[i] = a[i+1] - a[i];
	}
	
	c = m;
	for(int i =0;i<n - 1;i++){
		j = i;
		while(m>=0){
			for(;j<n;){
				zong++;
				if(cha[j] == 0){
					j++;
				}else{
					break;
				}
			}
			if(m>=0 && j < n + 1){
				cut = max(cut,zong);
			}else{
				break;
			}
			m = m - cha[j] * zong;
			j++;
		}
		zong = 0;
		m = c;
	} 
	
	cout<<cut;
	
	return 0;
}
