#include <bits/stdc++.h>

using namespace std;

int n,m;
int max_points=-114514;

int a[114514];
int shengyu[114514];

int first_find(string s,char c){
	int len=sizeof(s);
	for(int i=0;i<len;i++){
		if(s[i]==c)
			return i;
	}
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		max_points=max(max_points,a[i]);
	}
	for(int i=1;i<=n;i++){
		string cards="";
		int yu[114514]={0};
		for(int j=i;j<=n;j++){
			if(yu[a[j]]){
				for(int k=first_find(cards,a[j]+'0')+1;k<sizeof(cards);k++)
					yu[cards[k]-'0']=0;
				cards=cards.substr(0,first_find(cards,a[j]+'0')-1);
			}
			yu[a[j]]++;
			cards+=(char)(a[j]+'0');
		}
		cout<<yu[i]<<' ';
	}
}
