#include <bits/stdc++.h>

using namespace std;

int n;//有几个区间
char c[200100];//每个区间的字符
int s[200100][3];//每个区间的范围 
int sum = 0;//要改几次
int cnt;//有几个字母 

char find(int num){
	
	for(int i=1;i<=n;i++){
		if(num>=s[i][1] && num<=s[i][2]) return c[i];
	}
	
}

int main(){
	
	int o;//当前区间大小 
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> o;
		cnt += o;
		s[i][1] = s[i-1][2] + 1;
		s[i][2] = s[i][1] + o - 1;
		cin >> c[i];
	}
	
	int w1,w2;//要对比的两个字母的位置 
	char z1,z2;//要比的两个字母是啥
	int m;//居中的值  
	if(cnt%2!=0){
		m = cnt / 2 + 1;
		w1 = m;
		w2 = m;
		for(int i=1;i<=cnt/2;i++){
			w1 = m - i;
			w2 = m + i;
			z1 = find(w1);
			z2 = find(w2);
			if(z1!=z2) sum++;
		}
	}
	else{
		w1 = cnt / 2 + 1;
		w2 = cnt / 2;
		for(int i=1;i<=cnt/2;i++){
			w1--;
			w2++;
			z1 = find(w1);
			z2 = find(w2);
			if(z1!=z2) sum++;
		}
	}
	cout << sum;
	
	return 0;
}
