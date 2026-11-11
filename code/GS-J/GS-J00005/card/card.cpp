#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);  
	freopen("card.out","w",stdout);
	int n;
	int m;
	cin>>n>>m;
	vector<int> vec;
	vector<int> tj;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		vec.push_back(a);
	}
	for(int i=0;i<m;i++){
		tj.push_back(0);
	}
	vector<int> table;
	for(int j=0;j<n;j++){
		for(int i=0;i<n;i++){
			int flag=0;
			for(int c=0;c<table.size();c++){
				if(table[c]==vec[i]){
					flag=1;
					break;
				}
			}
			if(!flag)
				table.push_back(vec[i]);
			else{
				//cout<<"d"<<endl;
				for(int a=table.size()-1;a>=0;a--){
					//cout<<table[a]<<" "<<vec[i]<<"   ";
					if(table[a]==vec[i]){
						table.erase(table.begin()+a,table.end());
						break;
					}
				}
				table.push_back(vec[i]);
			}
			//cout<<vec[i]<<" "<<flag<<endl;
			//for(int g=0;g<table.size();g++){
			//	cout<<table[g]<<" ";
			//}
			//cout<<endl;
		}
		
		for(int b=0;b<table.size();b++){
			//cout<<table[b];
			tj[table[b]-1]++;
		}
		//cout<<endl<<endl;
		//for(int i=0;i<tj.size();i++){
		//	cout<<tj[i]<<" ";
		//}
		//cout<<endl<<endl;
		vec.erase(vec.begin());
		table.erase(table.begin(),table.end());
	}
	for(int i=0;i<tj.size();i++){
		cout<<tj[i]<<" ";
	}
	return 0;
}
