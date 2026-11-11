#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string cx1,wz1,cx2,wz2,res="";
	cin>>cx1>>wz1>>cx2>>wz2;
	if(cx1==cx2){
		res+="1";	
		string pai1="",pai2="";
		for(int i=0;i<=1;i++){
			pai1+=wz1[i];
			pai2+=wz2[i];
		}
		int lst1=(int)wz1[2],lst2=(int)wz2[2];
		if(pai1==pai2){
			res+="1";
			if(max(lst1,lst2)<=67 || min(lst1,lst2)>67){
				res+="1";
				if(abs(lst1-lst2)==1){
					res+="1";
				}
				else res+="0";
			}//Í¬Ò»²à 
			else res+="00";
		}
		else res+="000";
	}
	else res+="0000";
	
	cout<<res;
} 
