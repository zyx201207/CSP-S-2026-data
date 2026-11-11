#include<bits/stdc++.h>
using namespace std;
int pd(char s){
	if(s=='A'){
		return 1;
	}else if(s=='B'){
		return 2;
	}else if(s=='C'){
		return 3;
	}else if(s=='D'){
		return 4;
	}else if(s=='F'){
		return 5;
	}
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    bool sum=0,xl=0;
    //同一车厢
    if(c1==c2){
        cout << 1;
    }else{
        cout << 0;
        sum=1;
    }
    //同一排
    for(int i=0;i<=1;i++){
        if(s1[i]!=s2[i]){
            sum=1;
        }
    }
    if(sum==0){
        cout << 1;
    }else{
        cout << 0;
    }
    //同一侧
    int s1s=0,s2s=0;
	s1s=pd(s1[2]);
	s2s=pd(s2[2]);
    if(sum==0){
        if(s1s>s2s){
			if(s1s-s2s>=1&&s1s!=4&&s2s!=3){
				cout << 1;
			}else{
				cout << 0;
			}
		}else{
			if(s2s-s1s>=1&&s1s!=3&&s2s!=4){
				cout << 1;
			}else{
				cout << 0;
			}
		}
    }else{
        cout << 0;
    }
    //相邻
    if(sum==0){
        if(s1s>s2s){
			if(s1s-s2s==1&&s1s!=4&&s2s!=3){
				cout << 1;
			}else{
				cout << 0;
			}
		}else{
			if(s2s-s1s==1&&s1s!=3&&s2s!=4){
				cout << 1;
			}else{
				cout << 0;
			}
		}
    }else{
        cout << 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}