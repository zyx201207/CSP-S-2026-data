#include<bits/stdc++.h>
using namespace std;
int n;
long long z[200200];
char c[200200];
int l; // 当z全为1时用huiwen2 
int huiwen(char c[],long long z[]){
	int s = n;
	int d = 1;
	int flag = true;
	int i = 0;
	int j = 0;
	for(;s != d;){
		i++;
		j++;
		if(c[s] != c[d]){
			flag = false;
			break;
		}else{
			if(i == z[s]){
				s--;
				i = 0; 
			}
			if(j == z[d]){
				d++;
				j = 0;
			}
		}
	}
	if(flag == true){
		return 1;
	}else return 0;
}
int huiwen2(char c[]){
	bool flag = true;
	for(int i = 1,j = n;i != j;i++,j--){
		if(c[i] != c[j]) flag = false;
	}
	if(flag == true) return 1;
	else return 0;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	bool flag = true;
	bool flag1 = true;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> z[i] >> c[i];
		if(i != 1){
			if(c[i] != c[i-1]) flag = false;
			if(z[i] != z[i-1]) flag1 = false;
		}
	}
	if(flag == true){
		cout << 0;
		return 0;
	}
	if(flag1 == true){
		if(huiwen2(c)){
			cout << 0;
			return 0;
		}else{
			for(int i = 1;i <= n;i++) z[i] = 1;
			l = 1;
		}
	}
	if(huiwen(c,z) == 1){
		cout << 0;
		return 0;
	}
	return 0;
}
