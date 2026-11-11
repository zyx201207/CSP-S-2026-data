//owo
#include <bits\stdc++.h>
using namespace std;
string mmu;
char oil[1000000];
int yum[1000000];
long long int m,sum,nam;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>m;
	int u;
	for(int i=0;i<m;i++){
		cin>>yum[i];
		cin>>oil[i];
		sum+=u;
	}
	int l,r,pl,pr;
	l=0;
	r=m-1;
	pl=0;
	pr=0;
//	for(int i=0;i<m;i++){
//		cout<<oil[i]<<' '<<yum[i]<<endl;
//	}
	for(int i=0;r>=l;i++){
//		cout<<endl<<"对比区块"<<l<<'-'<<oil[l]<<"与"<<r<<'-'<<oil[r]<<'~'<<(oil[l]!=oil[r])<<endl;
		if(oil[l]!=oil[r]){
			if(yum[l]-pl<yum[r]-pr){
//				cout<<"右侧更长"<<endl; 
				nam+=yum[l]-pl;
				pr+=yum[l]-pl;
				pl=0;
				l++;
//				cout<<"目前浮标:"<<l<<' '<<pl<<'|'<<r<<' '<<pr<<endl;
			}
			else{
//				cout<<"左侧更长"<<endl;
				nam+=yum[r]-pr;
				pl+=yum[r]-pr;
				pr=0;
				r--;
//				cout<<"目前浮标:"<<l<<' '<<pl<<'|'<<r<<' '<<pr<<endl;
			}

		}
		else{
			if(yum[l]-pl<yum[r]-pr){
				pr+=yum[l]-pl;
				pl=0;
				l++;
//				cout<<"目前浮标:"<<l<<' '<<pl<<'|'<<r<<' '<<pr<<endl;
			}
			else{
				pl+=yum[r]-pr;
				pr=0;
				r--;
//				cout<<"目前浮标:"<<l<<' '<<pl<<'|'<<r<<' '<<pr<<endl;
			}
		}
		if(pl==yum[l]){
			pl=0;
			l++;
//			cout<<"目前浮标:"<<l<<' '<<pl<<'|'<<r<<' '<<pr<<endl;
		}
	}
	cout<<nam;
	return 0;
}
//aaaabbccc
