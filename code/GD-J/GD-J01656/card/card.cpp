#include<bits/stdc++.h>
using namespace std;

int used[300005];
int pos[300005];

void game(string s){ //pos[s[i]-'0']：当前点数的牌的位置   i：当前位置 
	for(int i=0;i<s.size();i++){  //遍历每一张牌的点数 
		if(pos[s[i]-'0']!=0){  //如果前面有这张牌 
			s.erase(pos[s[i]-'0'],i-pos[s[i]-'0']);  //删掉这些牌 
		}
		pos[s[i]-'0']=i;  //否则记录当前牌是点数位置 
	}
	for(int i=0;i<s.size();i++){
		used[s[i]-'0']++;
	} 
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	
	string s;
	
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		s=char(a+'0');
	}
	
	for(int i=1;i<=n;i++){
		s=s.substr(1);
		game(s);
	}
	
	for(int i=1;i<=m;i++){
		cout<<used[i]<<' ';
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
