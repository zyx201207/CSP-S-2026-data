#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
   	int x=0,f=1;char ch = getchar();
    while(ch < '0'||ch > '9'){if(ch == '-')f=-1;ch = getchar();}
    while(ch >='0'&&ch <='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const int N = 5e5+10;
int a[N];
int cnt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n = read(),m=read();
	vector<int> num;
	int k = 1;
	for(int i = 1;i <= n;i ++) {
		a[i] = read();
		for(int j = 0;j < num.size();j ++){
			if(a[i] == num[j]){
				for(int k = j;k < num.size();j ++){
					num.pop_back();
				}
			}
		}
		num.push_back(a[i]);
		for(int j = 0;j < num.size();j ++){
			cnt[num[j]] ++;
		}
	}
	for(int i = 1;i <= m;i ++){
		printf("%d ",cnt[i]);
	}
	return 0;
}

