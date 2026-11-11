#include <bits/stdc++.h>
using namespace std;
//孩子们，打表出省一 但是我已经没有机会了 
//加油，我要AFO了，中国信竞的未来靠你们了  
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool chexiang = 0,pai = 0;
	//车厢 
	if(c1==c2){
		cout<<1;
		chexiang = 1;
	}else{
		cout<<0;
	} 
	//排 
	if(chexiang){
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			cout<<1;
			pai = 1;
		}
		else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	//同侧 
	if(chexiang&&pai){
		if(s1[2] == 'A' && s2[2] == 'B' || s1[2] == 'B' && s2[2] == 'A'){
			cout<<1;
		}else if(s1[2] == 'A' && s2[2] == 'C' || s1[2] == 'C' && s2[2] == 'A'){
			cout<<1;
		}else if(s1[2] == 'B' && s2[2] == 'C' || s1[2] == 'C' && s2[2] == 'B'){
			cout<<1;
		}else if(s1[2] == 'D' && s2[2] == 'F' || s1[2] == 'F' && s2[2] == 'D'){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	//相邻 
	if(chexiang && pai){
		if(s1[2] == 'A' && s2[2] == 'B' || s1[2] == 'B' && s2[2] == 'A'){
			cout<<1;
		}else if(s1[2] == 'B' && s2[2] == 'C' || s1[2] == 'B' && s2[2] == 'C'){
			cout<<1;
		}else if(s1[2] == 'D' && s2[2] == 'F' || s1[2] == 'F' && s2[2] == 'D'){
			cout<<1;
		}else cout<<0;
	}else{
		cout<<0;
	}
	
	return 0;
}
//100稳了（真的吗？） 
