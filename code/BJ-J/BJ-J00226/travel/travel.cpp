#include<iostream>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int train1,train2;
    char seat1[4],seat2[4];
    cin >> train1 >> seat1 >> train2 >> seat2;
    int row1 = (seat1[0]-'0')*10+seat1[1];
    int row2 = (seat2[0]-'0')*10+seat2[1];
    bool bothTrain = (train1==train2);
    bool oneRow = bothTrain && (row1==row2);
    bool oneSide = oneRow && ((seat1[2]<='C'&&seat2[2]<='C')||(seat1[2]>='D'&&seat2[2]>='D'));
    bool nextTo = oneSide && abs(seat1[2]-seat2[2])==1;
    cout << bothTrain << oneRow << oneSide << nextTo;
    return 0;
}
