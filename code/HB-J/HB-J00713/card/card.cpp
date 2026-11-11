#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n , m , p = 0 , a = 0;
	cin >> n >> m;
	string s , x , v;
	for(int i= 1;i <= n;i ++){
		cin >> v;
		s += v;
	}for(int j = 1;j <= n;j ++){
		p ++;
		x.clear();
		for(int i = p;i <= n;i ++){
			if(a != 0){
				for(int k = 1;k <= a;k ++){
					if(x[k - 1] == s[i - 1]){
						s.replace(k - 1,a,"");
					}
				}
			}else{
				x += s[i - 1];
			}a ++;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
