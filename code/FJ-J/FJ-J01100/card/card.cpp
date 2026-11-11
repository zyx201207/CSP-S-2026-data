#include<bits/stdc++.h>
#define ll long long
#define rt return
#define ffor(a,b,c,d) for(int (a)=(b);(a)<(c);(a)+=(d))
using namespace std;
const int N=3e5;
int n,m,ax[N],ans;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	ffor(i,0,n,1){
		int a;
		cin>>a;
		ax[a]++;
	}
	ffor(i,1,m+1,1){
		ans+=ax[i];
		cout<<ans<<" ";
	}
	rt 0;
}
//code by Rufory  |100+68+(40,85]+(12,16]=(220,269]
//FJ-J01100

// fan zheng zhe ti ye bu hui ,gan cui zai zhe li xie ba

/*
 zhu: yw=yin wei , sy=suo yi
 yi zhi: I love Luo Tianyi,Tianyi blue=66CCFF.
 yw I love Luo Tianyi
 sy I love Tianyi blue
 sy I love 66CCFF
 zhu yi dao "66CCFF" bao han zi chuan "CCF"
 sy I love CCF
 sy CCF gives me some points! please! please!! please!!!!!
 
 orzorzstosto
 
 CCF shao ye ji jia you!
*/
