#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>

using namespace std;

const int MAX_man=5e5+5;
const int MAX_kin=3e5+5;

int many;
int kind;

long long int ppos[MAX_man];
long long int appe[MAX_kin];
bool into[MAX_kin];

vector <int> tree;

int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>many;
	cin>>kind;
	
	for(int i=1;i<=many;i++)
		cin>>ppos[i];
		
	for(int i=1;i<=many;i++){
		
		//cout<<"round="<<i<<endl;
		
		memset(into,false,sizeof(into));
		
		for(int puin=i;puin<=many;puin++){		//对于每一局放入不同的牌 
			
			//cout<<"put_in="<<ppos[puin];
			
			if(!into[ppos[puin]]){				//如果桌面上还没有此牌 
				//cout<<" no_this"<<endl;
				tree.push_back(ppos[puin]);

				into[ppos[puin]]=true;
			}
			else{								//如果桌面上已有此牌 
				//cout<<" have_this"<<endl;
				while(1){
					
					int rout=tree.back();
					//cout<<"current="<<rout<<endl;
					if(rout==ppos[puin])
						break;
					else{
						tree.pop_back();
						into[rout]=false;
					}
				}
			}
		}
		
		while(!tree.empty()){
			
			int current=tree.back();
			tree.pop_back();
			//cout<<current<<" ";
			
			appe[current]++;
		}
		
		//cout<<endl;
	}
	
	for(int i=1;i<=kind;i++)
		cout<<appe[i]<<" ";
		
	return 0;
}
