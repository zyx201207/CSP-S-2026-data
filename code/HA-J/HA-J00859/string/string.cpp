#include <bits/stdc++.h>
using namespace std;
long long n;
long long ah[200005],a[200005],num = 0;
char ch[200005],c[200005],yuan[200005],qian[100005],hou[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i<= n;i++){
		cin >> ah[i];
		cin >> ch[i];
	}int h=1;
	for (int i=1;i<=n;i++){
		if (ch[i]==ch[i+1]){
			a[h]+=ah[i];
			continue;
		}a[h]+=ah[i];
		c[h]=ch[i];
		h++;
	}h--;
	
	long long w = 1;
	for (int i = 1;i<=h;i++){
		for (int j = 1;j<=a[i];j++){
			yuan[w]=c[i];
			w++;
		}
	}w--;
	
	long long mid;
	if (w % 2 == 0){
		mid = w/2;
	}else{
		mid = (w-1)/2;
	}
	for (int i = 1;i<=mid;i++){
		qian[i]=yuan[i];
		hou[i]=yuan[w+1-i];
	}for (int i = 1;i<=mid;i++){
		if (qian[i]!=hou[i]){
			num++;
		}
	}cout << num;
	return 0;
}
