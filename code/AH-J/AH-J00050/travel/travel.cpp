#include <bits/stdc++.h>
using namespace std;
bool same(string x,string y){
    char cx=x[2],cy=y[2];
    if(cx>cy) swap(cx,cy);
    if(cy=='F'){
        if(cx=='D'){
            return true;
        }else{
            return false;
        }
    }else if(cy=='C'||cy=='B'){
        return true;
    }else if(cy=='D'){
		return false;
	}
	return false;
}
bool side(string x,string y){
	char cx=x[2],cy=y[2];
	if(cx>cy) swap(cx,cy);
	if(cy=='F'){
		if(cx=='D'){
			return true;
		}else{
			return false;
		}
	}else if(cy=='C'){
		if(cx=='B'){
			return true;
		}else{
			return false;
		}
	}else if(cy=='B'){
		return true;
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string x1,x2,y1,y2;
    cin >> x1 >> x2 >> y1 >> y2;
    cout << (x1==y1);
    cout << (x2[0]==y2[0]&&x2[1]==y2[1]&&x1==y1);
    if(x2[0]==y2[0]&&x2[1]==y2[1]&&x1==y1){
        cout << same(x2,y2);
		cout << side(x2,y2);
    }else{
        cout << 0;
        cout << 0;
    }
    return 0;
}
