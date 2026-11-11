#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("travel.in""r",stdin);
freopen("travel.out""w",stdout);
string c1,s1,c2,s2;
cin >> c1 >> s1 >> c2 >> s2;
char X,R;
int x[2];
int r[2];
int a[4];

if ((c1 == c2)){
    a[0] = 1;
    for (int i = 0;i <= 1;i++){
    x[i]  =c1[i];
cout << c1[i];
}

for (int i = 0;i <= 1;i++){
    r[i]  =c2[i];
cout << c2[i];
}

if (x == r){
    a[1] = 1;
}

else {
    a[1] = 0;
}
if ((X == R+1)||X == (R-1)||X == (R-2)||X == (R+2)){
    if((X =='C')&&(R !='D')||(X =='D')&&(R !='C')){
            a[2] = 1;
        }
     else {
        a[2] = 0;
     }
     }
else {
a[2] = 0;
}
if(((a[2] ==1)&&(a[1] ==1))&&((X == R+1)||(X == R-1)|| (X == 'D')&& (R == 'F')|| (R == 'D')&& (X == 'F'))){
    a[3] = 1;
}
else {
a[3] = 0;
}

}
else {
    for (int k = 0;k <=3;k++){
        a[k] = 0;
    }
}
for (int j = 0;j<=3;j++){
    cout << a[j];
}

return 0;
}

