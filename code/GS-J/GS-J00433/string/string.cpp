#include<bits/stdc++.h>
using namespace std;
long long ans;
struct P{
	int num;
	char c;
}f[200505];

int n;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> f[i].num >> f[i].c;		
	}
	int p1=1,p2=n;
	
	
	while(p1 < p2){
		if(f[p1].c != f[p2].c){
			if(f[p1].num == f[p2].num){
				ans += f[p1].num;
				p1++;
				p2--;
			}
			else{
				if(f[p1].num > f[p2].num){
					ans += f[p2].num;
					f[p1].num -= f[p2].num;
					p2--; 
				}	
				else{
					ans += f[p1].num;
					f[p2].num -= f[p1].num;
					p1++; 	
				}
			}
		}
		else{
			if(f[p1].num == f[p2].num) {
				p1++;
				p2--;
			}
			else{
				if(f[p1].num > f[p2].num){
					f[p1].num -= f[p2].num;
					p2--; 
				}	
				else{
					f[p2].num -= f[p1].num;
					p1++; 	
				}	
			}
		}
	}
	cout << ans;
	return 0;
}
