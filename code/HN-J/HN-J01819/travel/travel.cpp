#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;//R的车厢 R的座位  X的车厢 X的座位 
	if(c1==c2){//同一车 
		cout<<1; 
		if(s1[0]==s2[0]&&s1[1]==s2[1]){//同一排 
			cout<<1;
			int p1=max(s1[2],s2[2]);
			int p2=min(s1[2],s2[2]);
			if(p1<='C'&&p2<='C' || p1=='F'&&p2=='D'){//同一侧 
				cout<<1;
				if(p1-p2==1 && !(p1=='D'&&p2=='C')){//相邻 
					cout<<1;
				}else{
					cout<<0;
					return 0; 
				}
			}else{
				cout<<0<<0;
				return 0; 
			} 
		}else{
			cout<<0<<0<<0;
			return 0; 
		} 
		 
	}else{
		cout<<0<<0<<0<<0;
		return 0; 
	}
	
	return 0;
}
