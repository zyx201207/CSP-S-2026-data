#include<bits/stdc++.h>
using namespace std;
pair<int,string> pa1,pa2;
bool flag=0;
int n,m;
int main(){
	//令令令申申申申申提交前解除文件输入输出注释 
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>pa1.first>>pa1.second>>pa2.first>>pa2.second;
	if(pa1.second[2]=='F'){
		pa1.second[2]='E';
	}
	if(pa2.second[2]=='F'){
		pa2.second[2]='E';
	}
	if(pa1.first!=pa2.first){
		cout<<"0000";
	}else{
		cout<<"1";
//		cout<<'/';
		//同排 
		if(pa1.second[0]==pa2.second[0]&&pa1.second[1]==pa2.second[1]){
			cout<<"1";
			
//			cout<<'/';
			//同排一侧 
			if(pa1.second[2]=='D'&&pa2.second[2]=='E'||pa1.second[2]=='E'&&pa2.second[2]=='D'){
				cout<<"1";
				flag=1;
			}else if(pa1.second[2]!='D'&&pa1.second[2]!='E'&&pa2.second[2]!='D'&&pa2.second[2]!='E'){
				cout<<"1";
				flag=1;
			}else{
				cout<<0;
			}
//			cout<<'/';
			if((pa1.second[2]+1==pa2.second[2]&&pa1.second[2]!='C')||(pa1.second[2]-1==pa2.second[2]&&pa1.second[2]!='D')){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else{
			cout<<"000";
//			cout<<'/';
		}
		
		//相邻 
		
	}
	return 0;
}
