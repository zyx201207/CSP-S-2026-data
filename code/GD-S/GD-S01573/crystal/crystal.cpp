#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int m;
int key=1,rec=0;
long long a[50005];

void ku(){
	int com_n=0,com_num=0;
	int t_n=0,t_num=0;
	for(int i_k=0;i_k<n;i_k++){
		if(t_n != a[i_k]){
			t_n=a[i_k];
			t_num = 1;
		}else{
			t_num++;
		}
		
		if(com_num < t_num){
			com_n=t_n;
			com_num=t_num;
		}
		cout<<com_n;
	}
}

int main(){
	//freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	//ios:sync_with_stdio(false);
	//cin.tie(0);
	
	cin>>n>>m;
	//vector<long long> a(n);
	
	for(int i=0;i<n;i++){cin>>a[i];}
	for(int ii=0;ii<n;ii++){
		rec = 0;
		if(m==0){ku(); break;}
		for(int iii=0;iii<key;iii++){
			rec += (a[key] - a[iii]);
		}
		if(rec == m){
			for(int iaa=ii+1;iaa<n;iaa++){
				if(a[iaa]==a[key]){key++; continue;}
				else{break;}
			}
			break;
		}
		key++;
	}
	if(m==0){return 0;}
	cout<<key;
	return 0;
}
