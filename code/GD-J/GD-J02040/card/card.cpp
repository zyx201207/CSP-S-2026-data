#include<bits/stdc++.h> 
using namespace std;

const int MAXN = 600000;

int n,m;
int a[MAXN];

bool flag=0;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int tmp;
	
	cin >> n >> m;
	
	for(int i=0;i<n;i++){
		cin >> tmp;
		a[i] = tmp;
		if(i>=1 && a[i] >= a[i-1]){
			flag = 1;
		}
	}
	
	int tmp2 = 0;
	if(flag){
		int tmp1=a[0],cnt=1;
		for(int i=1;i<n;i++){
			if(tmp1 != a[i]){
				cout << cnt-tmp2;
				cout << " ";
				tmp1 = a[i];
				tmp2 = cnt;
			}
			else{
				cnt++;
			}
		}
		return 0;
	}
	else{
		
	}
	
	return 0; 
} 


