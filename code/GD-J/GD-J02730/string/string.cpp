#include <bits/stdc++.h>
using namespace std;

int ans=0,n,Scnt=0;//Scnt表示整个字符串的字符数 
int c[26];
string si="";

void swap(int s1,int s2){
	char tmp=si[s2];
	si[s2]=si[s1];
	si[s1]=tmp;
	cout<<si<<endl;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	memset(c,0,sizeof(c));
	//读入数据 
	cin>>n;
	for(int i=0;i<n;i++){
		int itmp;
		char stmp;
		cin>>itmp;
		cin>>stmp;
		c[stmp-'a']+=itmp;
		for(int j=0;j<itmp;j++){
			si+=stmp;
		}
	}

//	for(int i=0;i<26;i++){
//		cout<<c[i]<<" ";
//	}

	Scnt=si.size();
	int hScnt=si.size()/2;
	int cent;//中间字母 
	bool isk[hScnt];
	for(int i=0;i<26;i++){
		isk[i]=true;
	}
	
	bool f=true;
	for(int i=1;i<Scnt;i++){
		if(si[i]!=si[0]){
			f=false;
		}
	}
	if(f){
		cout<<0;
		return 0;
	}
	
	int dcnt=0;
	for(int i=0;i<c;i++){
		if(c[i]>0)dcnt++;
	}
	cout<<Scnt/dcnt;
	return 0;
	
	if(Scnt&1){//若Scnt为奇数 
		for(int i=0;i<26;i++){
			if(c[i]&1){ 
				int cent=i;
				break; 
			}
		}
		
		for(int i=0;i<hScnt;i++){
			if(si[i] != si[Scnt-1-i]){
				isk[i]=false;
//				cout<<isk[i];
			}
		}
		
		for(int i=0;i<hScnt;i++){
			if(si[i]=='a'+cent||isk[i]==false){
				ans++;
				swap(i,hScnt+1);
			}
		}
		for(int i=hScnt+1;i<Scnt;i++){
			if(si[i]=='a'+cent||isk[Scnt-1-i]==false){
				ans++;
				swap(i,hScnt+1);
			}
		}
		
		for(int i=0;i<hScnt;i++){
			if(!isk[i]){
				if(si[i]==si[Scnt-1-i]){
					isk[i]=true;
					continue;
				}
				for(int j=i+1;j<hScnt;j++){
					if(isk[j])continue;
					if(si[j]==si[i]){
						swap(Scnt-1-i,j);
						ans++;
						isk[i]=true;
						break;
					}else if(si[j]==si[Scnt-1-i]){
						swap(i,j);
						ans++;
						isk[i]=true;
						break;
					}else if(si[Scnt-1-j]==si[i]){
						swap(Scnt-1-i,Scnt-1-j);
						ans++;
						isk[i]=true;
						break;
					}else if(si[Scnt-1-j]==Scnt-1-i){
						swap(i,Scnt-1-j);
						ans++;
						isk[i]=true;
						break;
					}
				}
			}
		}
	}
	
	cout<<ans;
//打印每个字母出现数量 
//	for(int i=0;i<26;i++){
//		cout<<c[i]<<" ";
//	}
	
	//aabbcc 0 0 1 acbbca
	//aabbc 0 0 aacbb abcba
	return 0;
}
